inherit ROOM;
void create()
{
        set("short", "�µ�");
        set("long", @LONG
�������ƺ������ŵ����꽭�ϵ�ζ������Զ����佻�Ϫ�ͺͽ��ϵ�
�󲿷ֶ���һ����С�����¿ɰ���������ǰ������ǻ�ɫ�ģ��Ʋ�Ҳ
�ǻ�ɫ�ģ�������佻�Ϫȫ����������һƬ���롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bridge3",
  "west" : __DIR__"xiaoqiao", 
"southwest" : "/d/dali/xidajie3",]));	
        set("outdoors", "chenxiang");
        set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
