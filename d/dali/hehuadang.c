inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��԰���棬����һ�������������������ÿ����ʱ�����̼䷢����������ʤ����
�غ����ܽ�أ���������ɫ������ʢ��֮�գ������������ף�����Ϯ�ˣ�С�۵���
���⣬������������б��΢���������ɣ��ݺ���ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hehuadang1",
  "north" : __DIR__"bamboo_bridge3",
]));
        set("outdoors","fengyun");

        setup();
}
