inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����£�ƫ�����ɼҡ�
ˮ����������������ҡ��Ӱ�߽��ߣ�ƫ�Ʒ���鶡�
�⾰�ã��������б��
��¶��������Ӱ�����紵���֦������˼���ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"grassroom",
  "southeast" : __DIR__"liu",
]));

        setup();
}
