...  

이것은 item.class 파일이 현재 디렉터리에 존재하지 않기 때문에 찾을 수 없다는 메시지다. 아래와 같이 실행해서 이 문제를 해결할 수 있다.

    java -classpath ".;lib" ClasspathDemo2

리눅스, OSX와 같은 유닉스 계열의 시스템이라면 아래와 같이 콜론을 사용해야 한다.

    java -classpath ".:lib" ClasspathDemo2

옵션 -classpath는 자바를 실행할 때 사용할 클래스들의 위치를 가상머신에게 알려주는 역할을 한다.

2018-05-02, 생활코딩, https://opentutorials.org/course/1223/5527