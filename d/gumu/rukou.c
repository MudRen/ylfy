// Modify by csy 98/12/29
#include <ansi.h> 
inherit ROOM;

void create()
{
     set("short", HIY"��Ĺ"NOR);
     set("long", @LONG
����˶��񣬷����Լ��������֮�У��������ɣ�������ˡ�������Ƭ
��С�Ŀ����أ�һ��һ�˸ߵİ�ɫ����Բڣ�������У�Ĺ������ɭɭ�����ֹ�
ľ����ƽ��ʮ��������į����ɪ֮�⡣Ĺ�Ž����ߣ������ǹ�Ĺ�����ڡ���
Ĺ������������������������ٳ�����Ů��Ľ��������˫���ϱڿ��⽭���ĺ�
�飬����ǧ��ĥ�Ѻ��ճɾ����������顣��Զǧ������Ͷ�ݡ�
LONG        );

     set("outdoors","��Ĺ");
     set("valid_startroom",1);

     set("exits", ([
         "enter" : __DIR__"gmqt",
         "south" : __DIR__"xuanya",
         "north" : __DIR__"guoyuan",
         ]));

     setup();
     "/d/gumu/gumu_b"->foo();
} 
void init()
{       
        object ob = this_player();
                ob->set("startroom", "/d/gumu/rukou");
}
