범죄자의 범죄점수를 기록, 조회하는 프로그램입니다. 콘솔창에 신상정보와 범죄명을 입력하면 파일 내에 있는 기록들을 조회하여 기록이 이미 있다면 점수를 누적하여 수정 후 출력하고 없는 이름이라면 기록하도록 프로그램을 구성했습니다.

주요 함수로는 fopen과 fread 함수가 있습니다.
먼저 fopen 함수는 인자값에 따라 파일을 읽기전용, 쓰기전용 등으로 모드를 변경하여 파일을 여는 함수입니다. 인자값으로는 파일명, 파일모드명을 입력받습니다.
fread 함수는 파일 내에 기록된 자료들을 읽어들이는 함수입니다. 읽어서 내용을 담을 함수, 읽어올 데이터의 크기, 읽어올 데이터의 개수, 파일 스트림을 인자값으로 받습니다.

이 프로젝트를 진행하면서 기록을 읽어들인 후 그 값을 수정하는 작업이 어려웠습니다. 처음엔 fgets 함수로 전부 읽어들이고 전부 수정하는 방향으로 코드를 짰으나 fread 함수를 이용하여 한줄씩 읽은 후 줄의 맨 앞으로 커서를 이동시켜 한줄만 지운 후 다시 쓰도록 하여 문제를 해결했습니다.  
