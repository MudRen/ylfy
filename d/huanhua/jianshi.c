// jianshi.c ����
// by chenww

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
����������佻����ɵı�����,佻������ռ��ĺܶ�������ѷ���
����.����������µĵ��Ӷ�������ȡ����.
LONG
        );
        set("exits", ([
                "west" : __DIR__"xiaoxuan",
                "east" : __DIR__"zhenmei" ,
        ]));
        set("objects", ([
"/clone/weapon/changjian" : 2,	
                __DIR__"npc/xioagang" : 1,
                       ]));
  
        set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

