// edemote.c
// write by Fan 1997-12-21
inherit F_CLEAN_UP;
#include <ansi.h>
int in_use;
string emote_more()
{
	mapping emote;
	string *str,arg="";
	int i;		
	str=sort_array(EMOTE_D->query_all_emote(), 1);
	for (i=0;i<sizeof(str);i++){
	emote = EMOTE_D->query_emote(str[i]);
	arg+=sprintf(RED+"%s"+NOR+"�ϴ��޸ģ�%s\n",str[i], emote["updated"]);
	arg+=sprintf("��������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
		emote["myself"], emote["others"], emote["myself_self"],
		emote["others_self"], emote["myself_target"], emote["target"],
		emote["others_target"] );
	}
	return arg;
}
int main(object me, string arg)
{
        mapping emote,emote1;
        if( !arg ) return notify_fail("��Ҫ�༭ʲô emote��\n");
	if (arg=="all"){
		me->start_more(emote_more());
		return 1;
	}
        if( sscanf(arg, "-d %s", arg) ) {
                write("ɾ�� emote��" + arg + "\n");
                EMOTE_D->delete_emote(arg);
                return 1;
        }
        if( sscanf(arg, "-p %s", arg) ) {
                emote = EMOTE_D->query_emote(arg);
                printf("�ϴ��޸ģ�%s\n", emote["updated"]);
                printf("��������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                        emote["myself"], emote["others"], emote["myself_self"],
                        emote["others_self"], emote["myself_target"], emote["target"],
                        emote["others_target"] );
                return 1;
        }
	emote1= EMOTE_D->query_emote(arg);
        emote = EMOTE_D->query_emote(arg);
        emote = (["updated":geteuid(me)]);
        write("�༭ emote��" + arg + "\n");
        write("ѶϢ�����кü��У��� . ��ʾ������\n");
        write("ѶϢ�п�ʹ�õĲ��������¼��֣�\n");
        write("  $N  �Լ������֡�     �Լ����������֡�\n");
        write("  $n  ʹ�ö�������֡� ������������֡�\n");
        write("  $p  ʹ�ö�����˳ƴ����ʣ����㡢�㡢����������������\n");
        write("  $S  ���Լ��ĳƺ���   �����¡����ɡ�СŮ�ӡ�ƶɮ�ȡ�\n");
        write("  $s  ���Լ��Ĵ�³�ƺ����籾��������ү�ҡ����ӡ�\n");
        write("  $C  ���Լ����سơ��������ҡ�С���ҡ�����ҡ�С���ҡ�\n");
        write("  $c  �Ա��˵��سơ����硢�ܵܡ���㡢����\n");
        write("  $R  �Ա��˵���ơ����ɹá�С���׳ʿ����ʦ��\n");
        write("  $r  �Ա��˵Ĵ�³�ƺ�������ţ���ӡ���ͺ¿��������С���ˡ�\n");
        write("������������������������������������������������������������������������\n");
        write("��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
        write(emote1["others"]+"->");
        input_to("get_msg_others", emote,emote1, arg);
        return 1;
}
int get_msg_others(string msg, mapping emote, mapping emote1,string pattern)
{
        if (msg==".") {
		if (undefinedp(emote["others"]) && !undefinedp(emote1["others"])) 
			emote["others"]=replace_string(emote1["others"],"$P","$N");
		else
                if( !undefinedp(emote["others"]) ) emote["others"] =replace_string(emote["others"],"$P","$N")+ "\n";
                write("���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
	        write(emote1["others_self"]+"->");
                input_to("get_msg_others_self", emote,emote1, pattern);
                return 1;
        }
        if( !undefinedp(emote["others"]) )
                emote["others"] += msg + "\n";
        else emote["others"] = msg;
        write("->");
        input_to("get_msg_others", emote,emote1, pattern);
        return 1;
}
int get_msg_others_self(string msg, mapping emote, mapping emote1,string pattern)
{
        if (msg==".") {
		if (undefinedp(emote["others_self"])&& !undefinedp(emote1["others_self"])) 
                        emote["others_self"]=replace_string(emote1["others_self"],"$n","$p");
		else
                if( !undefinedp(emote["others_self"]) ) emote["others_self"] = replace_string(emote["others_self"],"$n","$p")+ "\n";
                write("�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��\n->");
	        write(emote1["target"]+"->");
                input_to("get_msg_target", emote,emote1, pattern);
                return 1;
        }
        if( !undefinedp(emote["others_self"]) )
                emote["others_self"] += msg + "\n";
        else emote["others_self"] = msg;
        write("->");
        input_to("get_msg_others_self", emote,emote1, pattern);
        return 1;
}
int get_msg_target(string msg, mapping emote, mapping emote1,string pattern)
{
        if (msg==".") {
		if (undefinedp(emote["target"])&& !undefinedp(emote1["target"])) 
                        emote["target"]=replace_string(emote1["target"],"$n","$p");
		else
                if( !undefinedp(emote["target"]) ) emote["target"] = replace_string(emote["target"],"$n","$n")+ "\n";
                write("�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��\n->");
	        write(emote1["others_target"]+"->");
                input_to("get_msg_others_target", emote,emote1, pattern);
                return 1;
        }
        if( !undefinedp(emote["target"]) )
                emote["target"] += msg + "\n";
        else emote["target"] = msg;
        write("->");
        input_to("get_msg_target", emote,emote1, pattern);
        return 1;
}
int get_msg_others_target(string msg, mapping emote, mapping emote1,string pattern)
{
		string emote_str;
        if (msg==".") {
		if (undefinedp(emote["others_target"])&& !undefinedp(emote1["others_target"])) 
			emote["others_target"]=emote1["others_target"];
		else
                if( !undefinedp(emote["others_target"]) ) emote["others_target"] += "\n";
                if( !undefinedp(emote["others"]) ) emote["myself"]=replace_string(emote["others"],"$N","$P");
                if( !undefinedp(emote["others_self"]) ){
					emote_str=emote["others_self"];
					emote_str=replace_string(emote_str,"$N","$P");
					emote["myself_self"]=emote_str;
		}
                if( !undefinedp(emote["target"]) ){
			emote_str=replace_string(emote["target"],"$N","$P");
			emote_str=replace_string(emote_str,"$p","$n");
			emote["myself_target"]=emote_str;
		}
                EMOTE_D->set_emote(pattern, emote);
                write("Emote �༭������\n");
                return 1;
        }
        if( !undefinedp(emote["others_target"]) )
                emote["others_target"] += msg + "\n";
        else emote["others_target"] = msg;
        write("->");
        input_to("get_msg_others_target", emote,emote1, pattern);
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : edemote [-d|-p] <emote>
 
���ָ������޸�, ɾ�� emote ���г�������. ���� -d ������ɾ��
ָ���� emote, -p ��������г�ָ�� emote ������. �г���˳�����
�� emote ʱ��ͬ.
 
���� emote ѶϢʱ��������Ŀ: û��Ŀ��, ָ��Ŀ����Ƕ��Լ�. ��
������ĳ��ѶϢ, ��ֱ���ڿհ������� '.' ����.
 
һ�� emote ѶϢ�����кܶ���, �ڿհ������� '.' ����������� emote.
 
�༭ emote ʱ���������µķ�������ʾ:
 
$N : �Լ�������.
$n : Ŀ�������.
$P : �Լ����˳ƴ�����.
$p : Ŀ����˳ƴ�����.
$S : ���Լ��ĳƺ���
$s : ���Լ��Ĵ�³�ƺ���
$C : ���Լ����سơ�
$c : �Ա��˵��سơ�
$R : �Ա��˵���ơ�
$r : �Ա��˵Ĵ�³�ƺ���
HELP
    );
    return 1;
}
