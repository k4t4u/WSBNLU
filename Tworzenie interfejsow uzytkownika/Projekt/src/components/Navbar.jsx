import { NavLink } from 'react-router-dom';
import { useState } from 'react';
import { Menu, X } from 'lucide-react';

const links = [
    { to: '/', label: 'Strona główna' },
    { to: '/offer', label: 'Oferta' },
    { to: '/contact', label: 'Kontakt' },
    { to: '/pricing', label: 'Cennik' },
    { to: '/services', label: 'Usługi' },
    { to: '/blog', label: 'Blog' },
    { to: '/reviews', label: 'Opinie' },
];

export default function Navbar() {
    const [open, setOpen] = useState(false);

    return (
        <header className="bg-gray-900 shadow-lg text-white relative z-50">
            <nav className="container mx-auto flex items-center justify-between py-4 px-6">
                <h1 className="text-2xl font-bold flex items-center gap-2">
                    🚗 MCS
                </h1>

                <button className="md:hidden z-50" onClick={() => setOpen(!open)}>
                    {open ? <X size={28} /> : <Menu size={28} />}
                </button>

                <ul className="hidden md:flex items-center gap-6">
                    {links.map((link) => (
                        <li key={link.to}>
                            <NavLink
                                to={link.to}
                                end
                                className={({ isActive }) =>
                                    `text-lg px-3 py-2 rounded transition ${
                                        isActive ? 'bg-blue-600' : 'hover:bg-gray-700 hover:underline'
                                    }`
                                }
                            >
                                {link.label}
                            </NavLink>
                        </li>
                    ))}
                </ul>
            </nav>

            {open && (
                <div className="fixed inset-0 bg-gray-900 flex flex-col items-center justify-center gap-6 md:hidden z-40">
                    {links.map((link) => (
                        <NavLink
                            key={link.to}
                            to={link.to}
                            end
                            className={({ isActive }) =>
                                `text-xl px-6 py-3 rounded-lg transition ${
                                    isActive ? 'bg-blue-600' : 'hover:bg-gray-700'
                                }`
                            }
                            onClick={() => setOpen(false)}
                        >
                            {link.label}
                        </NavLink>
                    ))}
                </div>
            )}
        </header>
    );
}
