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
  "northwest" : __DIR__"hehuadang2",
  "south" : __DIR__"bridge1",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/chong" : 3,
]));
        set("outdoors","dali");

        setup();
}
