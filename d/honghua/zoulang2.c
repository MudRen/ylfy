//Room /d/honghua/zuolang2.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
������һ�������������ϣ�����û��һ���ˣ���ĽŲ�
�����ú�Զ�����Գ�����Ĳк���ͣ�˼�ֻ�����ҽе�����
��������紵������������.
LONG
	);
	
	set("outdoors", "honghua");	
	set("exits", ([
          "south" : "/d/honghua/xiuxishi",
                "northup" : "/d/honghua/zongduo",
                "west"   : "/d/honghua/yixiangting",
           "eastdown" : __DIR__"zoulang" ,
	]));

	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	setup();

}
