inherit ROOM;
void create()
{
        set("short", "����ˮ");
        set("long", @LONG
����ˮ�����ƽ�԰�С�
б��ůҡ��䶯���仨��ů���ƺ죬ƻĩ����硣
����Ŀ����ԾС������
������ҡ�����ȣ�������Ӱ���ɹ���Զ������ء�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"jiu",
  "east" : __DIR__"grassroom",
]));

        setup();
}
