// Room: /d/wizard/fightroom5.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��ݺ��");
    set("long", @LONG
���Ǹ�����С�ĺ�����������ľ��������ݺ��ߴ�������ּ䴫����΢�紵
�����������ˡ���ˮ������ɫ�������䲻�󣬿ɺ�ˮȴ��ɲ⡣���߻��м���
���������������ǵ���˿������Ϫ����΢��������ƽ����Ϫ���ϻ���ȦȦ��㣬
����ˮ�е������ͣ��Ծ��ˮ�档��ֻ��ë������ԧ����ˮ���ϵ�����ȥ����ʱ
�ذ�ͷ̽��ˮ��Ѱ�����ǵ�ʳ����м�ֻ�ڰ�����Ϣ��
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/city/zuixianlou",
  "east" : __DIR__"fightroom4",
]));
    setup();
    replace_program(ROOM);
}
