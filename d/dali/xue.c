inherit ROOM;
void create()
{
        set("short", "����ѩ");
        set("long", @LONG
����ѩ���缱�黹�ࡣ
��Ƭ��ʱ���񻧣��ػ�������β�����������ĥ��
��ˮԶ�����ɫ��͡�
����Ī˼��Է���������������˸裬��������Σ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"liu",
  "southwest" : __DIR__"nu",
]));

        setup();
}
