// fanchuan.c ���� 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������ɽ�����ڣ����������󽫾����������ڴˣ����������
��;���ͻ��ƣ��ɰ�ɭӳ��ˮ������������䣬��Ȼ�н��ϵľ�ɫ�����
���߶���ׯ�ڵء�������һ���ϸ�С·��
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"westup" : __DIR__"sgroad1",
		"north" : __DIR__"zhuangjiadi1",
             "south" : "/d/wudang/wdroad8",
             "east" : __DIR__"zhuangjiadi2", 
          ]));
	setup();
	replace_program(ROOM);
}



