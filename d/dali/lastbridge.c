inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�������ɺ�«״���ڴ�һ�������������������ƻ�żפ��Զ���ƻ���㣬������Ӱ
ө�⣬�����ѱ档����ʱ��˪����𣬷��ֽ�Ⱦ�Ʊ̣�Ұ��˥��ܽ�أ���ӳˮ�ʣ�«έ
�к���Ⱥ������߿���ƣ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"nu",
  "west" : __DIR__"cao",
  "north" : __DIR__"bridge2",
  "south" : __DIR__"taban",
]));
        set("outdoors","dali");

        setup();
        replace_program(ROOM);
}
