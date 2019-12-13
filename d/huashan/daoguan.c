// Room: /d/huashan/daoguan.c
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
��յ��̨�����İ�����⣬�����������Ե������ɭ�ֲ���һ���ߴ������
�Ϲ�����֩�����������ϵĽ����Ѿ������˴�룬¶����������ߡ�����ǰ����
һ�������ҳ��Ĺ������������ҵ�ɢ���ż����ƾ����š����Ժ������˵ذڷ���
���߹ײġ�
LONG
);
        set("item_desc", ([ 
  "����" : "����ϸ�ع۲���һ���������������������ӵ�����---һ����������ظ����\n",
  "�ײ�" : "��������ŵ�Χ�Źײ����˼�Ȧ����������һ�߹ײĵĹײİ��������������\n",
  "�ײİ�" : "�ײİ��ϻ����ż����ߴ糤������˿���ĵ�����ӹײĵķ�϶��͸�˳��������������(prize)����\n",
]));
        setup();
}
void init()
{
   add_action("do_prize","prize");
}
int do_prize(string arg)
{
    object weapon;
	
    if (stringp(query("exits/enter")) && query("do_prize")) return 0;
    if( !arg || arg !="�ײİ�" ) 
         return notify_fail("��Ҫ��ʲô��\n" ) ;
    if (!objectp(weapon = this_player()->query_temp("weapon")))
        return notify_fail("������û�������ˣ�\n");
    if (weapon->query("skill_type")=="whip"
     || weapon->query("skill_type")=="hammer"
     || weapon->query("skill_type")=="throwing")
        return notify_fail("���ֱ�����ô�ˣ�\n");
        message_vision("$N���"+weapon->name()+"������ײĵķ�϶�����һ��������һ�ˡ�\n", this_player());
    if(this_player()->query_str()>200 && this_player()->query("neili")>200){
        message("vision","�ײİ�Ӧ���ɳ����⡣\n", this_object());
        this_player()->add("neili",-200);
        set("exits/enter",__DIR__"guancai");
        set("do_prize",1);
    }else{
        message_vision("$N�۵��������������ײİ�˿��������\n", this_player());
        this_player()->set("neili",0);
    }
    return 1;
}
int valid_leave(object me, string exit)
{
      if (exit=="enter"){
        delete("exits/enter");
        message_vision("$Nսս�������ɽ��ײ��\n");
      } 
      return 1;
}

