#!/usr/bin/env python3
"""Gera a seção de estatísticas do README a partir da estrutura do repositório.

Tudo é dinâmico: novos temas em Codeforces/, novas categorias em CSES/ e novas
pastas de prova no root aparecem automaticamente na próxima execução.
O conteúdo é injetado no README.md entre os marcadores STATS:START / STATS:END.
"""
import os
import re

# Raiz do repo = pasta-mãe deste script (scripts/), independente de onde for chamado.
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

CF_DIR = "Codeforces"
CSES_DIR = "CSES"
# Pastas que NÃO são provas (não entram na contagem de "Provas").
NON_CONTEST = {".git", ".github", "scripts", "assets", CF_DIR, CSES_DIR}

MARK_START = "<!-- STATS:START -->"
MARK_END = "<!-- STATS:END -->"


def count_cpp(path):
    return sum(
        1
        for _, _, files in os.walk(path)
        for f in files
        if f.endswith(".cpp")
    )


def subdir_counts(parent):
    """{nome_subpasta: nº de .cpp} para cada subpasta com pelo menos 1 .cpp."""
    out = {}
    if not os.path.isdir(parent):
        return out
    for name in sorted(os.listdir(parent)):
        p = os.path.join(parent, name)
        if os.path.isdir(p):
            n = count_cpp(p)
            if n:
                out[name] = n
    return out


def label(name):
    return name.replace("_", " ").replace("-", " ")


def mermaid_pie(title, data):
    """data: lista de (label, valor) já ordenada."""
    lines = ["```mermaid", "pie showData", f"    title {title}"]
    for lbl, val in data:
        lines.append(f'    "{lbl}" : {val}')
    lines.append("```")
    return "\n".join(lines)


def md_table(header, rows):
    out = ["| " + " | ".join(header) + " |",
           "|" + "|".join(["---"] * len(header)) + "|"]
    for r in rows:
        out.append("| " + " | ".join(str(c) for c in r) + " |")
    return "\n".join(out)


def build():
    cf = subdir_counts(CF_DIR)
    cses = subdir_counts(CSES_DIR)
    contests = {
        d: count_cpp(d)
        for d in sorted(os.listdir("."))
        if os.path.isdir(d) and d not in NON_CONTEST and not d.startswith(".")
        and count_cpp(d) > 0
    }

    cf_total = sum(cf.values())
    cses_total = sum(cses.values())
    prova_total = sum(contests.values())
    grand = cf_total + cses_total + prova_total

    cf_sorted = sorted(cf.items(), key=lambda kv: (-kv[1], kv[0]))
    cses_sorted = sorted(cses.items(), key=lambda kv: (-kv[1], kv[0]))
    contests_sorted = sorted(contests.items(), key=lambda kv: (-kv[1], kv[0]))

    parts = []
    parts.append(
        f"> **{grand}** problemas resolvidos · "
        f"**{cf_total}** Codeforces · **{cses_total}** CSES · "
        f"**{prova_total}** em provas ({len(contests)} competições)"
    )

    # Pizza 1 — distribuição por fonte
    parts.append("\n### Por fonte\n")
    parts.append(mermaid_pie("Problemas por fonte", [
        ("Codeforces", cf_total),
        ("CSES", cses_total),
        ("Provas", prova_total),
    ]))

    # Pizza 2 — Codeforces por tema
    parts.append("\n### Codeforces por tema\n")
    parts.append(mermaid_pie("Codeforces por tema",
                             [(label(k), v) for k, v in cf_sorted]))
    parts.append("")
    parts.append(md_table(["Tema", "Resolvidos"],
                          [(label(k), v) for k, v in cf_sorted]))

    # Pizza 3 — CSES por categoria
    parts.append("\n### CSES por categoria\n")
    parts.append(mermaid_pie("CSES por categoria",
                             [(label(k), v) for k, v in cses_sorted]))

    # Tabela de provas
    parts.append("\n### Provas & competições\n")
    parts.append(md_table(["Competição", "Problemas"],
                          [(label(k), v) for k, v in contests_sorted]))

    return "\n".join(parts) + "\n"


def main():
    block = build()
    with open("README.md", encoding="utf-8") as fh:
        readme = fh.read()
    pattern = re.compile(
        re.escape(MARK_START) + r".*?" + re.escape(MARK_END), re.DOTALL
    )
    new_block = f"{MARK_START}\n{block}{MARK_END}"
    if not pattern.search(readme):
        raise SystemExit(
            "Marcadores STATS:START/END não encontrados no README.md"
        )
    readme = pattern.sub(lambda _: new_block, readme)
    with open("README.md", "w", encoding="utf-8") as fh:
        fh.write(readme)
    print("README.md atualizado.")


if __name__ == "__main__":
    main()
