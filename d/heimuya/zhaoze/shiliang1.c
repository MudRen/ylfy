// Room: /d/heimuya/zhaoze/shiliang1.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ����͹��ƽ���ּ�����������֮�У�ʯ���ﻬ�쳣���ߵ�Խ������
��Խ���������һ�Σ�Ծ��һ��ȱ�ڣ����������߸����£��ۼ�����ɽ��
��һ��Ƭƽ�أ�ȱ�ڱ˶���ϥ����һ����������������һ���飬�������С�
LONG
);
        set("exits", ([ 
  "south" : __DIR__"shiliang",
]));
        set("outdoors", "shiliang1");

        setup();
}
void init()
{
       this_player()->delete_temp("reply_message");
      if (query("message"))  return;
   add_action("do_reply","answer");
      remove_call_out("send_message");
      call_out("send_message",3,this_player());
}

void send_message(object me)
{
        object room;

    if (!me || environment(me)!=this_object()) return;
        if (!room=find_object(__DIR__"shimao"))
        room=load_object(__DIR__"shimao");
   if (present("shu sheng",room)){
    switch (random(3)){
        case 0:
       message("vision",BOLD+"��������������ɪ���ã��˴���һ��ͷ�档\n"+NOR,this_object());
        set("message",1);
       break;
        case 1:
       message("vision",BOLD+"�����������������鵣�ǧ�ַ�ҡ�۵��ȡ�\n"+NOR,this_object());
        set("message",2);
       break;
        case 2:
       message("vision",BOLD+"��������������Į����ֱ��\n"+NOR,this_object());
        set("message",3);
       break;
    }
    remove_call_out("reply_message");
    call_out("reply_message",2,me);
    }
}
void reply_message(object me)
{
    if (!me || environment(me)!=this_object()) return;
    message_vision("��������վ����������������ָ��$N����λ"+RANK_D->query_respect(me)+"�ɷ�Գ�(answer)������\n",me);
    me->set_temp("reply_message",1);
}

int do_reply(string str)
{
     if (!str) return notify_fail("��������üͷ����ü����֮״��\n");
      message_vision(BOLD+"$N�����ش�"+str+"\n"+NOR,this_player());
     if (!this_player()->query_temp("reply_message")) return notify_fail("����������Ү��\n");
    switch (str){
    case "˪���Ҷ�����Ź����ң��":
    case "˪���Ҷ�����Ź����ң��":
    case "˪���Ҷ,���Ź����ң��":
      if (query("message")==2){
          message("vision","������һ˵��������������Ц��˵�������������������̹�������������֮������\n",this_object());
      remove_call_out("do_out");
      call_out("do_out",5,this_player());
    return 1;
       }
    case "�������ˣ���С����Զǳ�":
    case "�������ˣ���С����Զǳ���":
    case "��������,��С����Զǳ�":
      if (query("message")==1){
       message_vision("�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n",this_player());
      remove_call_out("do_out");
      call_out("do_out",5,this_player());
    return 1;
      }
    case "��������Բ��":
    case "��������Բ":
      if (query("message")==3){
       message_vision("�������ٺٵ���Ц��������˵���������㻹�������顣��\n",this_player());
      remove_call_out("do_out");
      call_out("do_out",5,this_player());
    return 1;
        }
    }
          message("vision","��������������ʲôƨ�ԣ���\n",this_object());
      
   return 1;
}

void do_out(object me)
{
    if (!me || environment(me)!=this_object()) return;
    message("vision","������Ц��һЦ��ת���ݹ�Сȱ�ڣ���������ա���\n",this_object());
    message_vision("$Nһ����������ȱ�ڡ�\n",me);
    me->move(__DIR__"shimao");
    delete("message");
}
int valid_leave(object me, string dir)
{
    if (dir=="south")   delete("message");
    return 1;
}

