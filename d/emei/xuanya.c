// Room: /d/emei/xuanya.c ������ ����

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����£������ͱ���ᾡ���������������һ�Ų��ɣ�֦Ҷï�ܣ�
������ա����������Ѳ�����һ���޴�����ߡ�
LONG
	);

	set("exits", ([
                 "down":__DIR__"shierpan4",
	]));
        set("objects",([
//                 "/d/emei/npc/snake": 1,
        ]));

        set("outdoors", "emei");
	setup();
}
void init()
{
       object obn,room;
       obn = new("/d/emei/npc/snake");
       room= load_object(__DIR__"xuanya");
       if(!objectp(present("snake")))
       {
       obn->move(room);
       return ;
         }
} 
