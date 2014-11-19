def flatten(nested):
    for sublist in nested:
        for element in sublist:
            yield element
