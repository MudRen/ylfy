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
  "north" : __DIR__"bridge",
  "south" : __DIR__"grassroom",
]));

        set("objects", ([
        __DIR__"npc/piaoke" : 1,
        __DIR__"npc/piaoke2" :1,
                        ]) );

        set("outdoors","dali");

        setup();
}
