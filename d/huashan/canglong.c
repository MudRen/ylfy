// canglong.c
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
��ɽ�������յ��Ǳ��壬����֮����͵����ǲ����롣�����
Լ���ף����һ�ף�����ɽ֮·������ɽ��֮�ϣ����༹�¹⻬ͦ�Σ���
���������䣬���������������һʯ��(shibei)��
    ��������������ɽ��·���������������ķ��·�������ǻ�ɽ���մ�
֮һ�������������¡���
LONG
    );
    set("exits", ([ /* sizeof() == 3 */
        "eastdown" : __DIR__"zhenyue",
        "southup" : __DIR__"sheshen",
    ]));
    set("objects", ([ 
        __DIR__"npc/liangfa" : 1,
    ]));
    set("item_desc", ([
        "shibei" :
"ʯ�����ż������֣�������֮Ͷ�鴦������˵���꺫�����ϴ���֮����\n"
"Ҳ��������������ΪҪ����ɽ�ϣ�����ɽ��д��Ͷ�������ͼ��˾��𡣺�\n"
"�����ǻ����ص��ع�������ɽ�����Ӱ������ŵ������ġ�\n"
    ])) ;
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    setup();
    replace_program(ROOM);
}
