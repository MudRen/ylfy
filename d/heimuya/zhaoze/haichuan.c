// Room: /d/heimuya/zhaoze/haichuan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ���洬�����Ҳ�����ض���ʮ���ˡ�һ����ʮ�����������
ָ���ż���������׳��ˮ�֣������˷緫���ں�����������
LONG
);

	setup();
}
void init()
{
    if (userp(this_player())){
       remove_call_out("drive_boat");
       call_out("drive_boat",10,this_player(),1);
    }
}
void drive_boat(object me,int i)
{
    if (!me && environment(me)!=this_object()) return;

    if (i<22)
    {
     i++;
       remove_call_out("drive_boat");
       message("vision",BLU+"���ں��Ϻ����˺ܾ�...�ܾ�.....\n"+NOR,this_object());
       call_out("drive_boat",10,this_player(),i);
        return;
    }
}
