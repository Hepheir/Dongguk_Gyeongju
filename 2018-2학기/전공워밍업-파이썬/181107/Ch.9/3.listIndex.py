heroes = ["아이언맨", "토르", "헐크", "스칼렛 위치"]
heroes[1] = "닥터 스트레인지"
print(heroes)

heroes.insert(1, "배트맨")
print(heroes)

heroes.remove("스칼렛 위치")
print(heroes)

del heroes[0]
print(heroes)

last_hero = heroes.pop()
print(last_hero)
print(heroes)

heroes = ["아이언맨", "토르", "헐크", "스칼렛 위치"]
print(heroes)
print(heroes.index("헐크"))

for hero in heroes:
    print(hero)

heroes.sort()
print(heroes)