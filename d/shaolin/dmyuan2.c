// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "��ĦԺ��¥");
    set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף���
�ٰ����ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼����
�ϱ�ɽǽ�Ǹ߼��ݶ��Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ���
�����ţ������а��ż��Ű���ڭ�ͼ����ţ���λ��ɮ�����붨�С�
LONG
    );
    set("exits", ([
        "down" : __DIR__"dmyuan",
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/xuan-bei" : 1,
        __DIR__"npc/xiao-bei" : 1,
    ]));
    setup();
    replace_program(ROOM);
}
