//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "������");
        set("long",@LONG
����ǡ��ƻ������Ļ����󡣷����ﵽ�������ʻ���������
���ϰ����ʻ�������ģ�Ҳ��һЩ�в��������滨��ݣ����˳��档
LONG
	);
        set("exits", ([
		"north" : __DIR__"damen",
		"south" : __DIR__"changlang",
                "west" : __DIR__"liangong",
                "east" : __DIR__"sleeproom",
        ]));

	set("objects",([
        "/kungfu/class/yihua/yuenu" : 1,
	]));
	set("valid_startroom", 1);
	setup();   }
