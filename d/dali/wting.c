inherit ROOM;
void create()
{
        set("short", "��ƫ��");
        set("long", @LONG
����һ��̨���������衣���������������������ζ������������¡���ʱ��ɫ
������������ҫ����ͬ���ա��������㣬���׷��档���;��黶Ц������������һ��
���������ȡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"corror",
  "north" : __DIR__"tading",
]));

       set("objects", ([
        __DIR__"npc/tianbg" : 1,
        __DIR__"npc/peijiunu" : 4,
                        ]) );

        setup();
}
