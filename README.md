# 42seoul_bsq
42seoul_bsq

20200720
1. read_f.c
- 같은 폴더 내 map 파일을 구조체 map_info로 변경
- file_to_struct 함수를 사용
2. tool.c
- 공용으로 자주 이용될 함수 모음
- strlen, atoi
3. map.pl
- 맵 생성 프로그램
- perl map.pl x y density
4. header
- 함수, 구조체 선언
5. map_info 구조체
- x : 가로
- y : 세로
- map : 맵 -> int 2차원 배열
- obst : 장애물 문자
- empty : 빈 공간 문자
- full : 채울 문자
