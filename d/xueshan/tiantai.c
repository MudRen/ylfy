//      tiantai.c ��̨
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","��̨");
        set("long",@LONG
������ѩɽ�µĸߴ������߿ɼ���ΰ�Ĵ�ѩɽ����ǧ��İ�ѩ
������ɽ��Ⱦ�ɰ�ɫ����ǰһƬ��ɫ���಻����̫��������������
���������ʰ�쵵�����㡣�ϱ�ε��ɫ��ʥ�����������·����
�������⡣
LONG
        );
        set("exits",([
                "west" : __DIR__"neidian",
        ]));
        setup();
        replace_program(ROOM);
}

