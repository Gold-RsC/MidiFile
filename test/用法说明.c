"MidiFile.h":
	header_file:
		stdio.h
		stdlib.h
		vector
		windows.h
	define:
		MIDIERR		-1
		NULL_TICK	-2 
		NULL_CHNL	-2 
		NULL_TRK	-2 
		NULL_PITCH	-2 
		NULL_VELO	-2 
		NULL_INSTRU	-2 
		NULL_BPM	-2
	variable:
		NOTEev null_of_note_event;
		NOTEev error_of_note_event(-1,-1,-1,-1,-1,-1);
		#define NULL_Nev null_of_note_event
		#define ERR_Nev error_of_note_event
		
		BPMev null_of_bpm_event;
		BPMev error_of_bpm_event(-1,-1);
		#define NULL_Bev null_of_bpm_event
		#define ERR_Bev error_of_bpm_event
	class(type):
		NOTEev
		BPMev
		NOTE//NOTEev����.��vectorʵ�� 
		BPM//BPMev����.��vectorʵ��
		MidiFile
		
	members:
		NOTEev:
			int tick,
				channel,track,
				pitch,velocity,
				instrument;//����
			//���캯�� 
			NOTEev(int tick=-2,int channel=-2,int track=-2,int pitch=-2,int velocity=-2,int instrument=-2);
			//�������캯�� 
			NOTEev(const NOTEev&note);
			//���ò��� 
			void set(int tick=-2,int channel=-2,int track=-2,int pitch=-2,int velocity=-2,int instrument=-2);
			//��ղ��� 
			void clear();
			//�������� 
			void copy(const NOTEev&note);
			//���в��� 
			void move(NOTEev&note);
			//�Ƚ� 
			bool operator==(NOTEev&note);
			bool operator!=(NOTEev&note);
		BPMev: //ͬ�� 
			int tick,
				value;
			BPMev(int tick=-2,int value=-2);
			BPMev(const BPMev&bpm);
			void set(int tick=-2,int value=-2);
			void clear();
			void copy(BPMev&bpm);
			void move(BPMev&bpm);
			bool operator==(BPMev&bpm);
			bool operator!=(BPMev&bpm);
		NOTE:
			//��Щ��Ů�޹� 
			int tick,channel,track,pitch,velocity,instrument;
			//���캯�� 
			NOTE();
			//�������캯�� 
			NOTE(const NOTE&sth);
			//��ĩβ��Ӳ��� 
			void push(NOTEev&sth);
			//����ĩβ�Ĳ��� 
			void pop();
			//������������ 
			void copy(NOTE&sth);
			//������������ 
			void move(NOTE&sth);
			//����������� 
			void clear();
			//�����Ƿ�Ϊ�� 
			bool empty();
			//����������� 
			int size();
			//���� 
			void sort();
			//����ĳ�±��Ӧ���� 
			NOTEev&operator[](int idx);
		BPM://ͬ�� 
			int tick,value;
			BPM();
			BPM(const BPM&sth);
			void push(BPMev&sth);
			void pop();
			void copy(BPM&sth);
			void move(BPM&sth);
			void clear();
			bool empty();
			int size();
			void sort();
			BPMev&operator[](int idx);
		MidiFile:
			//���캯�� 
			MidiFile();
			MidiFile(FILE*FIN);
			MidiFile(const char*filename);
			MidiFile(const MidiFile&other);
			//��ȡ 
			int read(FILE*FIN);
			int read(const char*filename);
			//�Ƿ��ȡ 
			bool is_read();
			//��ȡ�¼���Ϣ,
			//����ֵΪ�¼���Ϣ���¼����� 
			int get_tpqn();
			int get_fmt();
			int get_ntrk();
			int get_note(NOTE&sth);
			int get_bpm(BPM&sth);
			int get_ts_n();
			int get_ts_d();
			//�������� 
			~MidiFile();
"MidiFun.h" 
	header_file:
		MidiFile.h
	class(type):
		MidiFun
	member:
		MidiFun:
			//���캯�� 
			MidiFun();
			MidiFun(const MidiFun&other);
			MidiFun(const MidiFile&other);
			MidiFun(const char*filename);
			MidiFun(FILE*FIN);
			//��ʼ��(���캯�����в���ʱ�ɲ���) 
			void init(const char*filename);
			void init(FILE*FIN);
			void init(const MidiFile&other);
			//��ȡ�¼� 
			int get_tpqn();
			int get_fmt();
			int get_ntrk();
			int get_note(NOTE&sth);
			int get_bpm(BPM&sth);
			int get_ts_n();
			int get_ts_d();
			/***********************************************
			*���ߺ���
			*	����:pinit(NOTEev&),writecmd(<template>__FUNCTION); 
			*	������⣺
			*		pinit:
			*			����:(NOTE&),variable
			*		writecmd:
			*			����:(<template>__FUNCTION),function
			*			����:NOTEev,NOTEev(���ɼ�"&")
			*			����ֵ:void 
			*	����ֵ:void
			***********************************************/
			template<typename __FUNCTION>
			void makeline(NOTEev&pinit,__FUNCTION writecmd);
			//�������� 
			~MidiFun();
