
inherit ROOM;
void init();

void create()
{
	set("short","�ڶ�¥");
	set("long", @LONG
������ɱ��¥�ĵڶ�¥�������ס����ɱ��¥�Ķ���
�������ĳ�����һ��������ɱ֮����һ������������
����Ϧ����Ƶ�����ӳ��֮�£�˫Ŀ��¶��һ�����˲���
�ַ������ϣ�����������䣬��ů��ů�����ѱ������޲�
ɣ��
LONG
	   );
	set("exits",([
           "east" : __DIR__"qiandian",
	   ]));
	set("objects",([
                    __DIR__"npc/wuqiong":1,
//                     __DIR__"npc/shashou":6,
			]));
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
