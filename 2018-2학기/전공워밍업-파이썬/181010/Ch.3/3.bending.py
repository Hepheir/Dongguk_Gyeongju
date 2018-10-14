credit = int(input("투입한 돈:"))
price = int(input("물건값:"))

change = credit - price
print("거스름돈:", change)

_500Won = change // 500
_100Won = (change % 500) // 100
print("500원 동전의 개수:", _500Won)
print("100원 동전의 개수:", _100Won)
