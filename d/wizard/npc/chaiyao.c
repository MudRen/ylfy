// chaiyao zhuanjia.c
#include <ansi.h>
inherit NPC;
string *rnd_chat = ({
        "���Ǳ�����ҥŶ��С���ҽҴ��㡣",
});
varargs void drool(string msg, string player);
void create()
{
        set_name("��ҥר��", ({ "chaiyao zhuanjia" }) );
        set("gender", "����");
        set("age", 50);
        set("attitude", "friendly");
        set("combat_exp", random(20000));
        set("env/wimpy", 50);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: command, "get all" :),
                (: command, "wear all" :),
                (: command, "wield all" :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
}
int add_phrase(string player, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");
        if( msg!="" ) {
                add("memory/" + player, ({ msg }));
                return 1;
        } else return 0;
}
string make_reply()
{
}
void relay_channel(object ob, string channel, string msg)
{
        string player;
        if( !userp(ob) || (channel != "rumor") ) return;
        player = ob->query("name");
        if( ob==this_object() ) return;
        if( add_phrase(player, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}
void relay_chat(object ob, string msg)
{
        string player;
        if( !userp(ob) ) return;
        player = ob->query("name");
        if( ob==this_object() ) return;
        if( add_phrase(player, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("chat Ϊʲ�����ң���ʹҮ��");
                        break;
}
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
}
}
varargs void drool(string msg, string player)
{
        mapping mem;
        string *ob;
        mem = query("memory");
        if( !mapp(mem) ) return;
        if( !msg || !player) {
                ob = keys(mem);
                player = ob[random(sizeof(ob))];
                msg = mem[player][random(sizeof(mem[player]))];
}
        if( (strsrch(msg, "Ϊʲ��") >= 0) ) {
                if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
                switch(random(8)) {
                case 0: command("chat " + player + "��������������"); break;
                case 1: command("chat ���" + msg + " ... "); break;
                case 2: command("chat �� ... "); drool(); break;
                case 3: command("chat ��������� ...."); break;
                case 4: command("chat " + player + "��֪���������Ĵ𰸶���������Ҫ��"); break;
                case 5: command("chat " + msg + "��"); break;
                case 6: command("chat " + player + "���ܲ���˵���һ�㣿"); break;
                case 7: command("chat " + player + "���Ҳ������ʵ�����"); break;
}
}
        else if( (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "��", "��");
                switch(random(4)) {
                case 0: command("chat �� ... " + player + "˵�ú�"); break;
                case 1: command("chat " + player + "��Ϊʲ���" + "ҥ��" + "��������Ȥ��"); break;
                case 2: command("chat " + player + "�����С����ô����ҥ���أ�" ); break;
                case 3: command("chat " + player + "���Ǹ��߼����ˣ�" + "���첻�ݡ�"); break;
}
}
        else if( (strsrch(msg, "��") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "?", "");
                switch(random(7)) {
                case 0: command("chat ����˵" + msg + "��"); break;
                case 1: command("chat ��ģ�" + msg + "��");    break;
                case 2: command("hmm"); break;
                case 3: command("chat ����Ϊ" + msg + "��"); break;
                case 4: command("chat ����ͬ��"); break;
                case 5: command("chat ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ"); break;
                case 6: command("chat �йء�" + msg + "���Ļ��⵽��Ϊֹ����"); break;
}
        } else {
                switch(random(15)) {
                        case 0: command("chat Ϊʲ��˵" + msg + "?"); break;
                        case 1: command("chat ��" + msg + "����ʲ����˼��"); break;
                        case 2: command("chat " + msg + "��"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("chat ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("chat " + rnd_chat[random(sizeof(rnd_chat))]); break;
                        case 9: command("chat ������֪��" + msg + "?"); break;
                        case 10: command("chat �ո�" + player + "����˵�ˣ�" + msg); break;
                        case 11: command("chat �ҵ�Ȼ֪����" + msg); break;
                        case 12: command("chat Ȼ���أ�"); break;
                        case 13: command("chat �����"); break;
                        case 14: command("chat �Ҳ�������Ϊ��"); break;
                        default:
                                break;
}
}
}
void reset()
{
        delete("memory");
}
int accept_object()
{
        return 1;
}
