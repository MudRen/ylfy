inherit ROOM;
void create()
{
        set("short", "�Ͻ�ɳĮ");
        set("long", @LONG
����Ǻ�嫵���������ɴ�ɳĮ��һ�߽�������·���ʧ�˷���
��е�����ʮ�ֽ��ʣ����ǿ�Щ�뿪�ɡ�
LONG
        );
        set("exits", ([
        "northeast" : __DIR__"nanjiang",
        "southeast" : __DIR__"nanjiang3",
        "southwest" : __FILE__,
        "northwest" : __FILE__,
        "north" : __FILE__,
        "west" : "/d/npc/m_weapon/m_room1",
        "south" : __FILE__,
        "east" : __FILE__,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        int current_water;
        current_water = me->query("water");
        if (current_water==0) {
          write("���Ѿ��е������ˣ�ڤڤ����������˰���̧����ɽ���¡�\n");
          me->move(__DIR__"shanjiao");
          me->set("qi",-1);
    return notify_fail("���Ѿ��ʵò����ˡ�\n");
        }
        if (current_water>0 && current_water<=20) {
            write("�����ȱˮ����ð���ǡ�\n");
            me->set("water",0);
        }
        if (current_water>20) {
            me->set("water",current_water-20);
        }
        if (dir=="east" || dir=="south" || dir=="north") 
           return notify_fail("�����Ǳ���ȥ�������������ɳĮ�еĺ�����¥��\n");
    return 1;
}

