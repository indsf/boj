str = input()
result=''
for i in str:
    if i.isupper():
        result += i.lower()
    elif i.islower():
        result += i.upper()
    else:
        result += i
print(result)


    