inherit ROOM;
void create()
{
          set("short", "ͥԺ");
        set("long", @LONG
ͨ�԰���ۼ�Ϊ��ΰ������������ȴ������һ������ͥԺ������������
��ʣ�Ҳ���վ�ʧ�ޣ�����е��ѵ������е�������ɽ��é�ݡ�һ����ª����
LONG
        );
        set("exits", ([
                   "south" : __DIR__"damen",
                     "north" : __DIR__"road",
                     "west" : __DIR__"xiaomaowu",
         ]));
        set("objects", ([
       __DIR__"npc/asan" : 1,
       __DIR__"npc/asi" : 1,
        ]));
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}
