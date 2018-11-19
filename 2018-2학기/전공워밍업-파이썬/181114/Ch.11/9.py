import pickle

file = open("save.p", "rb")
obj = pickle.load(file)
print(obj)