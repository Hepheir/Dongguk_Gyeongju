import pickle
# 게임에서 사용되는 딕셔너리
gameOption = { 
			 "Sound": 8,
			 "VideoQuality": "HIGH",
			 "Money": 100000,
			 "WeaponList": ["gun", "missile", "knife" ]
}

# 이진 파일 오픈
file = open( "d:\\save.p", "wb" )
# 딕셔너리를 피클 파일에 저장
pickle.dump( gameOption, file )
# 파일을 닫는다.
file.close()
