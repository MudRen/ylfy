//      shenghu.c ʥ��
//      Designed by secret (����)
//      97/04/07
inherit ROOM;
void create()
{
        set("short","ʥ��");
        set("long",@LONG
    ��ǰ����������ʥ���������ĺ��浹Ӱ������Ͱ��ƣ�����ˮ��
�����Ŀ�������Զ����̻Ի͵�ѩɽ�������ɼ�����Զ���Ǽ��������
��ѩɽ��������ߴ������ɽ���ഫɽ�������ɾ�ס��ѩɽ���ڻ���ѩ
ˮ��������С�
LONG
        );
        set("resource/water",1);
        set("exits",([
                "south" : __DIR__"tulu3",
                "east" : __DIR__"hubian1",
        "west"  : "/d/npc/m_weapon/liangunshi",
        ]));
        setup();
        replace_program(ROOM);
}

