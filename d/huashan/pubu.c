// pubu.c
inherit ROOM;
void create()
{
    set("short", "ɽ���ٲ�");
    set("long", @LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵��ٲ���
��˵�������������������������ɾ��������������ġ�������ȥ�ȿգ�
ֻʣ�¿��ȵ�ɽ�Ⱥͱ��ڵĺ�ˮ(hongshui)��
LONG
);
    set("exits", ([ /* sizeof() == 1 */
        "northwest" : __DIR__"shaluo",
    ]));
    set("resource/water", 1);
    set("no_clean_up", 0);
    set("item_desc", ([
        "hongshui" : "����һ�ɱ��ڲ�Ϣ�ĺ�ˮ��ˮ�������и������ڷ��⣬���㶨\n
����ϸһ����������ֻ������ˮ�淴����չ����\n",
    ]));
    setup();
    replace_program(ROOM);
}
