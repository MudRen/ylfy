inherit ROOM;
void create()
{
          set("short", "С��");
        set("long", @LONG
ͨ�԰���Ȼ��ª��������Ȼ����ȴ���ݴ�ʧ��С������
����ֲ���ֻ��ݣ��������ӭ�洵�����ò���ˬ����������
������������
LONG
        );
        set("exits", ([
                       "north" : __DIR__"yishi",
                     "south" : __DIR__"road",
        ]));
        set("objects", ([
        ]));
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}
