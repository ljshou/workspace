import fileinput, re

field_pat = re.compile(r'\[(.+?)\]')

scope = {}

def replacement(match):
    code = match.group(1)
    print code
    try:
        return str(eval(code, scope))
    except SyntaxError:
        exec code in scope
        return ""

lines = []
for line in fileinput.input():
    lines.append(line)
text = ''.join(lines)

print field_pat.sub(replacement, text)

for k in scope.iterkeys():
    print k

