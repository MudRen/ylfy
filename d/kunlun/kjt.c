// Room: /d/kunlun/kjt.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�۾�̨");
	set("long", @LONG
���������ؾ������������ܣ�ֻ����ɽ�屻ѩ�����ţ�����Χӿ��ʮ��׳
�ۣ������Ŀ�������
LONG
	);
    set("objects", ([ 
        CLASS_D("kunlun")+"/banshuxian"  : 1,
    ]));
	set("outdoors", "kjt");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dt",
]));

	setup();
	replace_program(ROOM);
}
