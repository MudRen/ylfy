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
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"grassroom",
  "south" : __DIR__"lastbridge",
]));
        set("outdoors","dali");

        setup();
}
