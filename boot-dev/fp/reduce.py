# Assignment
import functools


def join(doc_so_far, sentence):
    if len(doc_so_far) == 0: return f"{sentence}."
    return f"{doc_so_far} {sentence}."


def join_first_sentences(sentences, n):
    if n == 0: return ""
    return functools.reduce(join, sentences[:n], "")
