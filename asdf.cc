filetype off
set nocompatible
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')
" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
Plugin 'ascenator/L9', {'name': 'newL9'}
Plugin 'Valloric/YouCompleteMe'
Plugin 'tpope/vim-surround'
Plugin 'tpope/vim-endwise'
Plugin 'morhetz/gruvbox'
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'tpope/vim-rails'
Plugin 'ngmy/vim-rubocop'
" Plugin 'scrooloose/syntastic'
Plugin 'scrooloose/nerdtree'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'MarcWeber/vim-addon-mw-utils'
Plugin 'tomtom/tlib_vim'
Plugin 'garbas/vim-snipmate'
Plugin 'tomtom/tcomment_vim'
Plugin 'ecomba/vim-ruby-refactoring'
Plugin 'airblade/vim-gitgutter'
Plugin 'Yggdroot/indentLine'
Plugin 'alvan/vim-closetag'
Plugin 'taglist.vim'
Plugin 'mileszs/ack.vim'
Plugin 'vim-ruby/vim-ruby'
Plugin 'vim-scripts/ruby-matchit'
" All of your Plugins must be added before the following line
call vundle#end()            " required
set exrc
filetype plugin indent on    " required
let g:gruvbox_italic=1
let g:gruvbox_termcolors=16
colorscheme gruvbox
autocmd!
set number
syntax on
set tags+=./tags;
set foldlevel=1
let mapleader=','
map <leader>fi :setlocal foldmethod=indent<cr>
map <leader>fs :setlocal foldmethod=syntax<cr>
map <leader>e :NERDTreeToggle<CR>
nmap <leader>r :NERDTreeFocus<cr> \| R \| <c-w><c-p>
map <leader>t :TlistToggle<CR>
map <C-F12> :!ctags -R --exclude=.git --exclude=logs --exclude=doc .<CR>
au BufRead,BufNewFile *.rb setlocal tags+=~/.vim/tags/ruby_and_gems
" set statusline+=%#warningmsg#
" set statusline+=%{SyntasticStatuslineFlag()}
" set statusline+=%*
" let g:syntastic_check_on_open = 1
" let g:syntastic_check_on_wq = 0
" let g:syntastic_auto_loc_list = 1
" let g:syntastic_always_populate_loc_list = 1
" let g:syntastic_ruby_checkers = ['rubocop']
set expandtab
set autoindent
set background=dark
autocmd Filetype html setlocal ts=2 sts=2 sw=2
autocmd Filetype ruby setlocal ts=2 sts=2 sw=2
autocmd Filetype cpp setlocal ts=2 sts=2 sw=2
autocmd Filetype javascript setlocal ts=4 sts=4 sw=4
let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files . -co --exclude-standard', 'find %s -type f']
let g:indentLine_setColors = 0
let g:indentLine_concealcursor = 'inc'
let g:indentLine_conceallevel = 2
let g:indentLine_color_gui = '#A4E57E'
let g:ackprg = 'ag --nogroup --nocolor --column'
set list 
set listchars=tab:>- 
" Use tab and shift-tab to cycle through windows.
nnoremap <Tab> <C-W>w
nnoremap <S-Tab> <C-W>W
set incsearch
set ignorecase
set smartcase
set hlsearch
nnoremap \l :setlocal number!<CR>
nnoremap \q :nohlsearch<CR>
nnoremap \o :set paste!<CR>
if has("vms")
  set nobackup
else
  set backup
  set undofile
endif
" Make CTRLP enter open files in new tab
let g:ctrlp_prompt_mappings = {
    \ 'AcceptSelection("e")': ['<c-t>'],
    \ 'AcceptSelection("t")': ['<cr>', '<2-LeftMouse>'],
    \ }
" Open definition in new tab or new vertical split when using ctrP
map <C-\> :tab split<CR>:exec("tag ".expand("<cword>"))<CR>
map <A-]> :vsp <CR>:exec("tag ".expand("<cword>"))<CR>
" custom ignores
set wildignore+=*/tmp/*,*.so,*.swp,*.zip   

" Keymaps for system copy and paste 
noremap <leader>y "*y<CR>
noremap <leader>p "*p<CR>
noremap <leader>Y "+y<CR>
noremap <leader>P "+p<CR>
" nmap j gj
" nmap k gk
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
