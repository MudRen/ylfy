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
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"bridge",
  "west" : __DIR__"hehuadang1",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/ouseller" : 1,
]));
        set("outdoors","dali");

        setup();
}
