# Assignment

def word_count_memo(document, memos):
    memos_copy = memos.copy()
    if memos_copy.get(document): return memos_copy[document], memos_copy
    memos_copy[document] = word_count(document)
    return memos_copy[document], memos_copy


# Don't edit below this line


def word_count(document):
    count = len(document.split())
    return count

