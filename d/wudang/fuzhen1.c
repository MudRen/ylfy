// fuzhen1.c �����һ��
// by arnzh 97/1/24
inherit ROOM;
void create()
{
    set("short", "�����һ��");
    set("long", @LONG
����һ���ս��õĵ��ۣ���ǰһ��������Ҷ����"�����"��������
������������龭�ĵط����䵱����Ҳ�������������������飬�����䵱��
��ά����ʢ����֧��֮һ���������������ֵ�һֽ���¾�����ȥ�����ж���
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "east" : __DIR__"xuanwumen",
        "eastup" : __DIR__"fuzhen2",
    ]));
        set("objects", ([
                CLASS_D("wudang") + "/zhixiang" : 1,
                       ]));
        setup();
    replace_program(ROOM);
}
