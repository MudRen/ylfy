// sanqingdian.c �����
inherit ROOM;
void create()
{
    set("short", "�����");
    set("long", @LONG
���������������������䵱�ɻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���������Ͼ��������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż�
�����š��������������ȣ��ϱ�������Ĺ㳡�������Ǻ�Ժ��
LONG
    );
//set("valid_startroom", 1);
    set("exits", ([
        "south" : __DIR__"guangchang",
//      "north" : __DIR__"houyuan",
//      "east" : __DIR__"donglang1",
//      "west" : __DIR__"xilang",
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/guxu" : 1,
        CLASS_D("wudang") + "/song" : 1]));
    setup();
        "/clone/board/wudang_b"->foo();
}
