//road1.c ����·
// by Xiang
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
	set("long", @LONG
����һ����ʯ�����Сɽ�ڣ���������ͨ�����ϵĴ�·��.
��˵ǰ��������Ұ�޳�û�����ɾ�����
LONG
	);
        set("outdoors", "wudang");
        set("exits", ([
                "northwest" : "/d/wudang/wdroad5",
                "west" : __DIR__"linjxd1.c",
                "east" : __DIR__"dating4",
        ]));
        set("objects",([  
           __DIR__"npc/laozhe" : 1 ,])); 
        setup();
        replace_program(ROOM);
}
