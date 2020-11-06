#include"header_file\MidiFun.h"

void test1(){
	MidiFun mid("mid\\windmill.mid");
	NOTE note;
	FILE*w=fopen("out_file\\test1.mcfunction","w");
	mid.get_note(note);
	int count_note=note.size();
	for(int idex=0;idex<count_note;idex++)
		if(note[idex].velocity)
			fprintf(w,"execute @a[scores={tick=%d}] ~~~ playsound %da.%d @s ~~~ %lf 1 0\n",note[idex].tick,note[idex].instrument,note[idex].pitch,(note[idex].velocity/127.0));		
	fprintf(w,"scoreboard players add @a tick 1");
	fclose(w);
}

FILE*test2_file;
void test2_writecmd(NOTEev a,NOTEev b){
	if(b.channel!=9)
		fprintf(test2_file,"(%d,%d)---(%d,%d)\n",a.tick,a.pitch,b.tick,b.pitch);
}
void test2(){
	MidiFun mid;
	mid.init("mid\\windmill.mid");
	test2_file=fopen("out_file\\test2.txt","w");
	NOTEev pinit(-10,-2,-2,64,128,-2);
	mid.makeline(pinit,test2_writecmd);
	fclose(test2_file);
}


void test3(){
	MidiFun mid("mid\\windmill.mid");
	NOTE note;
	mid.get_note(note);
	FILE*w=fopen("out_file\\test3.txt","w");
	//������ 
	int size=note.size();
	//������
	int ntrk=mid.get_ntrk();
	for(int i=0;i<size;i++){
		bool flag=0;
		if(note[i].channel==9){
			fprintf(w,"(%d,%d)��ͨ��9(��0Ϊ��һͨ��)��,�������Ϊ%d\n",note[i].tick,note[i].pitch,note[i].instrument);
			flag=1;
		}
		if(note[i].track==1){
			fprintf(w,"(%d,%d)������1(��0Ϊ��һ����)��,�������Ϊ%d\n",note[i].tick,note[i].pitch,note[i].instrument);
			flag=1;
		}
		if(flag)
			fprintf(w,"\n");
	}
	fclose(w);
}

void test4(){
	FILE*w=fopen("out_file\\test4.txt","w");
	NOTEev a;
	if(a==NULL_Nev)
		fprintf(w,"���Ǹ���NOTEev�¼�\n");
	if(a.tick==NULL_TICK)
		fprintf(w,"��tickΪ��\n");
	//�յ�note��̬���� 
	NOTE arr;
	if(arr[114514]==ERR_Nev)
		fprintf(w,"��NOTEev�¼�����\n");
}
int main(){
	//������������(����) 
	test1();
	//����������Ч(makeline����) 
	test2();
	//track��channel��ʹ�� 
	test3();
	//���÷� 
	test4();
	
	MessageBox(NULL,"��Ҫ�ر�ע���һ��:\nͨ�����Ϊ9ʱ [ һ�� ] (�ж������)Ϊ�����,��ʱ�������Ϊ������������,��NOTEev��instrument��Ա�޹�!!!","Gold_RsC��ܰ��ʾ",MB_ICONEXCLAMATION|MB_OK);
	int ret=MessageBox(NULL,"�ǵø��ҵ���Ƶ����","Gold_RsC",MB_ICONEXCLAMATION|MB_YESNO);
	while(ret==7)
		ret=MessageBox(NULL,"����ʧ��\n�ǵø��ҵ���Ƶ����","Gold_RsC",MB_ICONEXCLAMATION|MB_YESNO);
	MessageBox(NULL,"лл�ݹ�","Gold_RsC",MB_ICONEXCLAMATION|MB_YESNO);
	return 0;
}
