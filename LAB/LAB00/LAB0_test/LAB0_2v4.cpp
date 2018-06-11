


While (buffer is not empty)) {
Print One Line;
WordCount (buffer, WC);
Print Count (WC)
}


Print TotalWordCount;
WordCount(buffer, WC)
//Initialize pointer IN=1, OUT=0; //단어가 시작되면 state= IN이 됨
int i = 0; int state = OUT; // 단어가 시작되지 않음

while (buffer[i] != '\0') { //Until End of Line
if (isalpha(buffer[i])) {
if (state == OUT) { ++wc; state = IN;
} //문자 이고 state=IN이면 do nothing
else if (buffer[i] == ' ')
state = OUT;
i++;
}
