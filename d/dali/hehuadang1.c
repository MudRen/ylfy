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
  "east" : __DIR__"hehuadang2",
  "west" : __DIR__"hehuadang",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/dayan" : 2,
]));
        set("outdoors","dali");

        setup();
}
