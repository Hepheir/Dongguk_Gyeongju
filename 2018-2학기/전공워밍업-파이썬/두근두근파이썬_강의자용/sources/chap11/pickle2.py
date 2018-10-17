import pickle
# 이진 파일 오픈
file = open( "d:\\save.p", "rb" )
# 피클 파일에 딕션너리를 로딩
obj = pickle.load( open( "save.p", "rb" ) )
print(obj)
